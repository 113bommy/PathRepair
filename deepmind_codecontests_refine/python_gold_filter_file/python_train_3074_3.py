from sys import stdin,stdout
r,w = stdin.readline,stdout.write
s,x = map(int,r().split());andShft = s-x
w('%i\n' %(0 if andShft&1 or s<x or x&(andShft>>1) else 2**(f'{x:b}'.count('1')) - (2 if s == x else 0)))