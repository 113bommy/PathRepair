import sys
i=1
for a in sys.stdin:
 a=a.strip()
 if'0'==a:break
 print(f'Case {i}: {a}');i+=1
