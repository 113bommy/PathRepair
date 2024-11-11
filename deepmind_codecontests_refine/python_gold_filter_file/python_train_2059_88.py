A,V=map(int,input().split())
B,W=map(int,input().split())
T=input()
if ((V-W)*int(T)) < abs(B-A):
    print('NO')
else:
    print('YES')
