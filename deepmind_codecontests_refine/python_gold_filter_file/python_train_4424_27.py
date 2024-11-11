import sys

s = input()
for l in range(len(s)+1) :
      for r in range(l+1,len(s)+1) :
            if s[:l]+s[r:]=='CODEFORCES' :
                  print('YES')
                  sys.exit(0)
print('NO')
