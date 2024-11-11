a, b, k = map(int, input().split())
if k < a:
  a=a-k
else:
  b=max(b-(k-a),0)
  a=0
print(a,b)