import sys
import math
from collections import defaultdict,Counter,deque
# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
	newlines = 0

	def __init__(self, file):
		self._fd = file.fileno()
		self.buffer = BytesIO()
		self.writable = "x" in file.mode or "r" not in file.mode
		self.write = self.buffer.write if self.writable else None

	def read(self):
		while True:
			b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
			if not b:
				break
			ptr = self.buffer.tell()
			self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
		self.newlines = 0
		return self.buffer.read()

	def readline(self):
		while self.newlines == 0:
			b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
			self.newlines = b.count(b"\n") + (not b)
			ptr = self.buffer.tell()
			self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
		self.newlines -= 1
		return self.buffer.readline()

	def flush(self):
		if self.writable:
			os.write(self._fd, self.buffer.getvalue())
			self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
	def __init__(self, file):
		self.buffer = FastIO(file)
		self.flush = self.buffer.flush
		self.writable = self.buffer.writable
		self.write = lambda s: self.buffer.write(s.encode("ascii"))
		self.read = lambda: self.buffer.read().decode("ascii")
		self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# mod=pow(10,9)+7
n=int(input())
x=list(map(int,input().split()))
c=[0]*(n+1)
visit=set()
for j in x:
	c[j]+=1
	visit.add(j)
mi=0
ma=0
flag=0
for j in range(1,n+1):
	if flag%3:
		flag+=1
		continue
	if c[j]:
		mi+=1
		flag+=1
start=-1
cur=0
for j in range(1,n+1):
	if c[j]==0:
		if start!=-1:
			ma+=j-start
			if j-start==cur:
				pass
			elif cur-(j-start)==1:
				if start-1 not in visit:
					visit.add(start-1)
					ma+=1
				else:
					visit.add(j)
					ma+=1
			else:
				if start-1 not in visit:
					visit.add(start-1)
					ma+=1
				visit.add(j)
				ma+=1
			start=-1
			cur=0
	else:
		if start==-1:
			start=j
		cur+=c[j]

if start!=-1:
	ma+=n+1-start
	if n+1-start==cur:
		pass
	elif cur-(n+1-start)==1:
		ma+=1
	else:
		if start-1 not in visit:
			ma+=1
		ma+=1
print(mi,ma)