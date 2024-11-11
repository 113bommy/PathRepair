n = int(input())

for i in range(n):
  freqp = {}

  p = input()
  h = input()

  for i in range(len(p)):
    if(freqp.get(p[i])):
      freqp[p[i]] += 1
    else:
      freqp[p[i]] = 1

  resp = "NO"

  for i in range(len(h)-len(p)+1):
    freqh = {}
    for j in range(i, i+len(p)):
      if(freqh.get(h[j])):
        freqh[h[j]] += 1
      else:
        freqh[h[j]] = 1

    if(freqp == freqh):
      resp = "YES"

  print(resp)