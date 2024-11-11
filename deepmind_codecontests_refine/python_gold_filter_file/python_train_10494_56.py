n, a, b, c, d = map(int, input().split())
s = input()

if '##' in s[a:c-1]:
  print('No')
  exit()
if '##' in s[b:d-1]:
  print('No')
  exit()
if c > d:
  if '...' not in s[b-2:d+1]:
    print('No')
    exit()

print('Yes')
