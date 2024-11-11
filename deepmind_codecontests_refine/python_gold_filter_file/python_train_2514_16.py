#complexity - O(n)
n = int(input())
s = list(map(int, list(input())))
d = dict(zip(range(1, 10), map(int, input().split())))

def is_greater_equal(digit):
  return d[digit] >= digit

i = 0
ran_once = False
while i < n and not ran_once:
  if d[s[i]] > s[i]:
    while i < n and is_greater_equal(s[i]):
      ran_once = True
      s[i] = d[s[i]]
      i += 1
  i += 1 #Does not matter, for running once

print("".join(map(str, s)))
