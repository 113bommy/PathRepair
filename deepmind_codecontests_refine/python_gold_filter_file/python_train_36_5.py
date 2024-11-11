import sys
import math
  
n = int(sys.stdin.readline())
an = sys.stdin.readline()

d = [0] * 3

for i in range(n):
    if(an[i] == 'A'):
        d[0] += 1
    elif(an[i] == 'F'):
        d[1] += 1
    elif(an[i] == 'I'):
        d[2] += 1
   
if(d[2] == 1):
    if(d[1] != 0 or d[0] != 0):
        print(d[2])
    else:
        print(0)
elif(d[0] != 0 and d[2] == 0):
    print(d[0])
else:
    print(0)