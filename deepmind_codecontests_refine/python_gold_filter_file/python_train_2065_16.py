n=int(input())
s=list(map(int,input().split()))
a=0
while all(i%2==0 for i in s):
  s=[i//2 for i in s]
  a+=1
print(a)