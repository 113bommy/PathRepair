# Author : nitish420 --------------------------------------------------------------------
import os
import sys
from io import BytesIO, IOBase

def main():
	n,m=map(int,input().split())
	arr=[0]+list(map(int,input().split()))
	seg=[]
	for _ in range(m):
		seg.append(list(map(int,input().split())))
	ans=-float('inf')
	z=0
	zz=[]
	for i in range(1,n+1):
		mx=arr[i]
		temp=arr.copy()
		flag=0
		temp1=[]
		for k,item in enumerate(seg):
			l,r=item
			if l<=i<=r:
				continue
			flag+=1
			for j in range(l,r+1):
				temp[j]-=1
			temp1.append(k+1)
		mm=min(temp[1:])
		if ans<mx-mm:
			ans=mx-mm
			zz=temp1.copy()
			z=flag

	print(ans)
	print(z)
	print(*zz)
			



# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
	newlines = 0

	def __init__(self, file):
		self._fd = file.fileno()
		self.buffer = BytesIO()
		self.writable = 'x' in file.mode or 'r' not in file.mode
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
			self.newlines = b.count(b'\n') + (not b)
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
		self.write = lambda s: self.buffer.write(s.encode('ascii'))
		self.read = lambda: self.buffer.read().decode('ascii')
		self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')



# endregion

if __name__ == '__main__':
	main()