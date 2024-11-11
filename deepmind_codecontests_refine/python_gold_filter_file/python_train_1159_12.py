# Problem: C. Birthday
# Contest: Codeforces - Codeforces Round #541 (Div. 2)
# URL: https://codeforces.com/problemset/problem/1131/C
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

n=int(input())
A=sorted([int(_) for _ in input().split()])

i=0
while i<n:
	print(A[i],end=" ")
	i+=2
if n&1==1:
	i-=3
else:
	i-=1
while i>-1:
	print(A[i],end=" ")
	i-=2