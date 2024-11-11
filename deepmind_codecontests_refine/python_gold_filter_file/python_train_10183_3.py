import heapq
n,k = (int(x) for x in input().split())
arr = []
discard = []
type = set()
score = 0

for i in range(n):
  a,b = (int(x) for x in input().split())
  heapq.heappush(arr, (-b, a))
  
# 初期状態
for i in range(k):
  d, t = heapq.heappop(arr)
  score -= d
  if t not in type:
    type.add(t)
  else:
    heapq.heappush(discard, (-d, t))

bonus = len(type)
ans = score + bonus**2

while arr and discard:
  pd, pt = heapq.heappop(arr)  #追加候補
  if pt not in type:
    _pd, _pt = heapq.heappop(discard) #被っているものの中で美味しさが最も小さいものを取り出す
    type.add(pt)
    score = score - _pd - pd
    bonus += 1
    tmp = score + bonus**2
    ans = max(ans, tmp)
    
print(ans)
    

