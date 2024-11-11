import sys
for b in sys.stdin:
 for i in range(26):
  c=''.join([e,chr((ord(e)-96+i)%26+97)][96<ord(e)<123]for e in b)
  if any(('the'in c,'this'in c,'that'in c)):print(c.strip())
