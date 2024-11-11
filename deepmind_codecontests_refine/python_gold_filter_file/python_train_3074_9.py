import io
import sys
import time
import random
#~ start = time.clock()
#~ test = '''3 3''' # 2 solutions, (1,2) and (2,1)
#~ test = '''9 5''' # 4 solutions
#~ test = '''5 2''' # 0 solutions
#~ test = '''6 0''' # 1 solution
#~ sys.stdin = io.StringIO(test)

s,x = list(map(int, input().split()))

#~ print(s,x)

bitlen = s.bit_length()

def bits_of(x,bitlen):
   return [int((1<<i)&x!=0) for i in range(bitlen)]

sbits = bits_of(s,bitlen)
xbits = bits_of(x,bitlen)
overflows = bits_of(s^x,bitlen+1)

#~ print("s",sbits)
#~ print("x",xbits)
#~ print("overflows",overflows)

count = 1
if overflows[0]!=0 or s<x:
   count = 0
else:   
   zero_is_solution = True
   for i in range(bitlen):
      sumof_a_and_b = 2*overflows[i+1]+sbits[i]-overflows[i]
      #~ print(i,":",xbits[i],overflows[i+1],sbits[i],sumof_a_and_b)
      if (sumof_a_and_b==0 and xbits[i]==1) or \
         (sumof_a_and_b==1 and xbits[i]==0) or \
         (sumof_a_and_b==2 and xbits[i]==1) or \
         sumof_a_and_b>2 or sumof_a_and_b<0:
            count = 0
            break
      if sumof_a_and_b==1 and xbits[i]==1:
         count *= 2
         
      #~ if sumof_a_and_b==0 and xbits[i]==0:
         #~ print("s",(0,0))
      #~ if sumof_a_and_b==1 and xbits[i]==1:
         #~ print("s",(0,1),(1,0))
      if sumof_a_and_b==2 and xbits[i]==0:
         #~ print("s",(1,1))
         zero_is_solution = False
      
if count>0 and zero_is_solution:
   #~ print("R")
   count -= 2

print(count)   


#~ dur = time.clock()-start
#~ print("Time:",dur)
