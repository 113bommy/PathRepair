s = input()
ans = 'WA'
if s[0] == 'A' and s[2:-1].count('C') == 1\
   and s.replace('A', '').replace('C', '').islower():
  ans = 'AC'
print(ans)
