n = int(input())
s = input()

_s = []
_s.append(s[0])

s = '#'+s+"####"
for i in range (2, n+1):
     if ((s[i] != 'a') and (s[i] != 'e') and (s[i] != 'o') and (s[i] != 'u') and (s[i] != 'i') and (s[i] != 'y')): _s.append(s[i]) 
     else :
          if (s[i] != s[i-1]): 
               _s.append(s[i])
          else: 
               if ((s[i-1] == s[i]) and (s[i-1] != s[i-2]) and (s[i] != s[i+1]) and (s[i] == 'e' or s[i] == 'o')): _s.append(s[i]); 

for i in range (0, len(_s)):
     print (_s[i], end = '')