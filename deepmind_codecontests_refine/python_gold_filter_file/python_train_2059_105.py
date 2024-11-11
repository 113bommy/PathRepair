A,V=map(int,input().split())
B,W=map(int,input().split())
T=int(input())
print(['YES','NO'][abs(B-A)/(V-W)>T] if V-W>0 else 'NO')