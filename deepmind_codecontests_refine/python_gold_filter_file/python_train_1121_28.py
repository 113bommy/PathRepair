import sys
import operator
from itertools import repeat, islice
from functools import partial, reduce
from typing import Iterable, MutableSequence, Optional, Tuple, Union

Indices = Union[int, slice, Tuple[Union[int, slice]]]


class nd (list):
	def __getitem__(self, indices : Union[int, slice, Tuple[Union[int, slice]]]):
		if isinstance(indices, (int, slice)):
			return super().__getitem__(indices)
		else:
			return reduce(operator.getitem, indices, self)
	
	def __setitem__(self, indices : Union[int, slice, Tuple[Union[int, slice]]], value):
		if isinstance(indices, (int, slice)):
			super().__setitem__(indices, value)
		else:
			*rest_indices, last_index = indices
			self[rest_indices][last_index] = value
	
	def fill(self, value):
		for i in range(len(self)):
			element = super().__getitem__(i)
			if isinstance(element, nd):
				element.apply_inplace(value)
			else:
				super().__setitem__(i, value)
	
	def apply(self, func):
		return type(self)(
			(
				element.apply(func)
				if isinstance(element, nd)
				else func(element)
			)
			for element in self
		)
	
	def apply_inplace(self, func):
		for i in range(len(self)):
			element = super().__getitem__(i)
			if isinstance(element, nd):
				element.apply_inplace(func)
			else:
				super().__setitem__(i, func(element))
	
	def operate(self, other, operator):
		if not isinstance(other, list):
			other = repeat(other)
		return type(self)(
			(
				element.operate(other_element, operator)
				if isinstance(element, nd)
				else operator(element, other_element)
			)
			for element, other_element in zip(self, other)
		)
	def roperate(self, other, operator):
		if not isinstance(other, list):
			other = repeat(other)
		return type(self)(
			(
				element.roperate(other_element, operator)
				if isinstance(element, nd)
				else operator(other_element, element)
			)
			for element, other_element in zip(self, other)
		)
	def ioperate(self, other, operator):
		if not isinstance(other, list):
			other = repeat(other)
		for i, (element, other_element) in enumerate(zip(self, other)):
			if isinstance(element, nd):
				element.ioperate(other_element, operator)
			else:
				super().__setitem__(i, operator(element, other_element))
		return self
	def rioperate(self, other, operator):
		if not isinstance(other, list):
			other = repeat(other)
		for i, (element, other_element) in enumerate(zip(self, other)):
			if isinstance(element, nd):
				element.rioperate(other_element, operator)
			else:
				super().__setitem__(i, operator(other_element, element))
		return self
	def __add__(self, other):
		return self.operate(other, operator.add)
	def __radd__(self, other):
		return self.roperate(other, operator.add)
	def __iadd__(self, other):
		return self.ioperate(other, operator.add)
	def __sub__(self, other):
		return self.operate(other, operator.sub)
	def __rsub__(self, other):
		return self.roperate(other, operator.sub)
	def __isub__(self, other):
		return self.ioperate(other, operator.sub)
	def __mul__(self, other):
		return self.operate(other, operator.mul)
	def __rmul__(self, other):
		return self.roperate(other, operator.mul)
	def __imul__(self, other):
		return self.ioperate(other, operator.mul)
	def __matmul__(self, other):
		return self.operate(other, operator.matmul)
	def __rmatmul__(self, other):
		return self.roperate(other, operator.matmul)
	def __imatmul__(self, other):
		return self.ioperate(other, operator.matmul)
	def __truediv__(self, other):
		return self.operate(other, operator.truediv)
	def __rtruediv__(self, other):
		return self.roperate(other, operator.truediv)
	def __itruediv__(self, other):
		return self.ioperate(other, operator.truediv)
	def __floordiv__(self, other):
		return self.operate(other, operator.floordiv)
	def __rfloordiv__(self, other):
		return self.roperate(other, operator.floordiv)
	def __ifloordiv__(self, other):
		return self.ioperate(other, operator.floordiv)
	def __mod__(self, other):
		return self.operate(other, operator.mod)
	def __rmod__(self, other):
		return self.roperate(other, operator.mod)
	def __imod__(self, other):
		return self.ioperate(other, operator.mod)
	def __divmod__(self, other):
		return self.operate(other, operator.divmod)
	def __rdivmod__(self, other):
		return self.roperate(other, operator.divmod)
	def __idivmod__(self, other):
		return self.ioperate(other, operator.divmod)
	def __pow__(self, other):
		return self.operate(other, operator.pow)
	def __rpow__(self, other):
		return self.roperate(other, operator.pow)
	def __ipow__(self, other):
		return self.ioperate(other, operator.pow)
	def __lshift__(self, other):
		return self.operate(other, operator.lshift)
	def __rlshift__(self, other):
		return self.roperate(other, operator.lshift)
	def __ilshift__(self, other):
		return self.ioperate(other, operator.lshift)
	def __rshift__(self, other):
		return self.operate(other, operator.rshift)
	def __rrshift__(self, other):
		return self.roperate(other, operator.rshift)
	def __irshift__(self, other):
		return self.ioperate(other, operator.rshift)
	def __and__(self, other):
		return self.operate(other, operator.and_)
	def __rand__(self, other):
		return self.roperate(other, operator.and_)
	def __iand__(self, other):
		return self.ioperate(other, operator.and_)
	def __xor__(self, other):
		return self.operate(other, operator.xor)
	def __rxor__(self, other):
		return self.roperate(other, operator.xor)
	def __ixor__(self, other):
		return self.ioperate(other, operator.xor)
	def __or__(self, other):
		return self.operate(other, operator.or_)
	def __ror__(self, other):
		return self.roperate(other, operator.or_)
	def __ior__(self, other):
		return self.ioperate(other, operator.or_)
	def __neg__(self, other):
		return self.apply(other, operator.neg)
	def __pos__(self, other):
		return self.apply(other, operator.pos)
	def __abs__(self, other):
		return self.apply(other, operator.abs)
	def __invert__(self, other):
		return self.apply(other, operator.invert)
	def __lt__(self, other):
		return self.operate(other, operator.lt)
	def __le__(self, other):
		return self.operate(other, operator.le)
	def __eq__(self, other):
		return self.operate(other, operator.eq)
	def __ne__(self, other):
		return self.operate(other, operator.ne)
	def __gt__(self, other):
		return self.operate(other, operator.gt)
	def __ge__(self, other):
		return self.operate(other, operator.ge)
	
	@classmethod
	def full(cls, fill_value, shape : Union[int, Tuple[int], Iterable[int]]):
		if isinstance(shape, int):
			return cls(repeat(fill_value, shape))
		elif not isinstance(shape, tuple):
			shape = tuple(shape)
		
		if len(shape) == 1:
			return cls(repeat(fill_value, shape[0]))
		else:
			return cls(
				map(
					partial(cls.full, fill_value),
					repeat(shape[1:], shape[0])
				)
			)
	
	@classmethod
	def fromiter(cls, iterable, ndim=1):
		if ndim == 1:
			return cls(iterable)
		else:
			return cls(
				cls.fromiter(element, ndim-1)
				for element in iterable
			)
	
	@classmethod
	def nones(cls, shape : Union[int, Tuple[int], Iterable[int]]):
		return cls.full(None, shape)
	
	@classmethod
	def zeros(cls, shape : Union[int, Tuple[int], Iterable[int]], type=int):
		return cls.full(type(0), shape)
	
	@classmethod
	def ones(cls, shape : Union[int, Tuple[int], Iterable[int]], type=int):
		return cls.full(type(1), shape)
	
	@classmethod
	def partial_map(cls, func, *left_args, **left_kwargs):
		def nd_func(a, *right_args, **right_kwargs):
			return cls.fromiter(
				func(*left_args, v, *right_args, **left_kwargs, **right_kwargs)
				for v in a
			)
		return nd_func
	
	@classmethod
	def vectorize(cls, func, *left_args, **left_kwargs):
		def nd_func(a : nd, *right_args, **right_kwargs):
			return a.apply(lambda v: func(
				*left_args, v, *right_args, **left_kwargs, **right_kwargs
			))
		return nd_func


def bytes_to_str(x : bytes):
	return x.decode('utf-8')

def inputs(func=bytes_to_str, sep=None, maxsplit=-1):
	return map(func, sys.stdin.buffer.readline().split(sep=sep, maxsplit=maxsplit))

def inputs_1d(func=bytes_to_str, **kwargs):
	return nd(inputs(func, **kwargs))

def inputs_2d(nrows : int, func=bytes_to_str, **kwargs):
	return nd.fromiter(
		(inputs(func, **kwargs) for _ in range(nrows)),
		ndim=2
	)

def inputs_2d_T(nrows : int, func=bytes_to_str, **kwargs):
	return nd.fromiter(
		zip(*(inputs(func, **kwargs) for _ in range(nrows))),
		ndim=2
	)
from bisect import bisect_left, bisect_right
from collections import deque


N, M = inputs(int)
A, B, C = inputs_2d_T(N, int)
D, E, F = inputs_2d_T(M, int)
xs = sorted(set(C))
ys = sorted(set(D))

x_guard = nd.zeros((len(xs)+1, len(ys)+1), type=bool)
y_guard = nd.zeros((len(xs)+1, len(ys)+1), type=bool)

C = nd.partial_map(bisect_right, xs)(C)
A = nd.partial_map(bisect_left, ys)(A)
A += 1
B = nd.partial_map(bisect_right, ys)(B)

D = nd.partial_map(bisect_right, ys)(D)
E = nd.partial_map(bisect_left, xs)(E)
E += 1
F = nd.partial_map(bisect_right, xs)(F)

for a, b, c in zip(A, B, C):
	for y in range(a, b):
		x_guard[c, y] = True

for d, e, f in zip(D, E, F):
	for x in range(e, f):
		y_guard[x, d] = True

cow = (
	bisect_right(xs, 0),
	bisect_right(ys, 0)
)
nexts = deque([cow])
visited = nd.zeros((len(xs)+1, len(ys)+1), type=bool)

area = 0

while nexts:
	xi, yi = nexts.popleft()
	if visited[xi, yi]:
		continue
	
	visited[xi, yi] = True
	if 0 < xi < len(xs) and 0 < yi < len(ys):
		area += (xs[xi] - xs[xi-1]) * (ys[yi] - ys[yi-1])
		if not x_guard[xi, yi]:
			nexts.append((xi-1, yi))
		if not x_guard[xi+1, yi]:
			nexts.append((xi+1, yi))
		if not y_guard[xi, yi]:
			nexts.append((xi, yi-1))
		if not y_guard[xi, yi+1]:
			nexts.append((xi, yi+1))
	else:
		area = 'INF'
		break

print(area)

