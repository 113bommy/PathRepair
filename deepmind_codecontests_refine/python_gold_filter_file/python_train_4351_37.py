A1=list(map(int, input().split()))
A2=list(map(int, input().split()))
A3=list(map(int, input().split()))
A=A1+A2+A3
N=int(input())
s=set()
for _ in range(N):
  b=int(input())
  if b in A:
    s|={A.index(b)}
bingo=[{0,1,2},{0,3,6},{0,4,8},{1,4,7},{2,4,6},{2,5,8},{3,4,5},{6,7,8}]
print(["No","Yes"][any(s>=b for b in bingo)])

