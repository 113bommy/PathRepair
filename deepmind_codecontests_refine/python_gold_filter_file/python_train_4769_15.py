import heapq
N = int(input())
st = input()
n, a, b = map(int,st.split())

minvalue = b
left = [-a]
right = [a]
ptnum = 1
for i in range(N-1):
  st = input()
  if st[0] == '1':#入力クエリ
    n, a, b = map(int,st.split())
    if ptnum%2 == 1:#lrは一致
      l = - heapq.heappop(left)
      r = heapq.heappop(right)
      le = min(l,a)
      ri = max(a,r)
      heapq.heappush(left, -le)
      heapq.heappush(right, ri)
      minvalue += abs(l-a)
    else:#lr は必ずしも一致しない
      if a < -left[0]:#中央がlに
        heapq.heappush(left, -a)
        heapq.heappush(right, -left[0])
        minvalue -= a+left[0]
      elif a > right[0]:#中央がrに
        heapq.heappush(left, -right[0])
        heapq.heappush(right, a)
        minvalue += a-right[0]
      else:
        heapq.heappush(left, -a)
        heapq.heappush(right, a)
        
    minvalue += b
    ptnum += 1

  else:
    print(- left[0], minvalue)  