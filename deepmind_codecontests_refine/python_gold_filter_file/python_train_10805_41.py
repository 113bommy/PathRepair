def solve():
  ans = 0
  N = int(input())
  stacks = [list(map(lambda x:int(x)-1, input().split()))[::-1] for _ in range(N)]
  lis = [0]*N
  cnt = 0
  now = 0
  flag = 0
  while cnt<N*(N-1)//2:
    while not stacks[now]:
      now = (now+1)%N
    a = stacks[now][-1]
    if not stacks[a]:
      return -1
    if stacks[a][-1] == now:
      lis[now] = max(lis[now],lis[a])+1
      lis[a] = lis[now]
      stacks[a].pop(-1)
      stacks[now].pop(-1)
      cnt += 1
      flag = 0
    else:
      now = a
      flag += 1
    if flag==N:
      return -1
  ans = max(lis)
  return ans
print(solve())