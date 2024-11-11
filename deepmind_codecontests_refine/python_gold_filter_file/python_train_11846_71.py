K=int(input())
cnt=0
n=100
while n<K:
  n+=n//100
  cnt+=1
print(int(cnt))