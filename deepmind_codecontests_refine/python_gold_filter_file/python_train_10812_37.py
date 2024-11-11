s = input()
k = int(input())
v = list(s)
n = len(s)
a = [0 for i in range(n)]

for i in range(n):
  a[i] = (123 - ord(s[i]))%26
  if k == 0:
    break
  if k >= a[i]:
    v[i] = 'a'
    k -= a[i]

if k > 0:
  k %= 26
  v[n-1] = chr(ord(v[n-1])+k)
print (''.join(v))