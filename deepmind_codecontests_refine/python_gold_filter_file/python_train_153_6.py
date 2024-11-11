cnt=0; b=0
import sys
for s in sys.stdin:
   if s[0]=='+': cnt+=1
   elif s[0]=='-': cnt-=1
   else: b=b+(len(s)-2-s.find(':'))*cnt
print(b)
