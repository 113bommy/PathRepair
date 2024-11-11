'''
n: number of elements, 1 ≤ n ≤ 10**5
a1 ... an: integers
is it possible to sort the array a (in increasing order) by reversing 
exactly one segment of a?

Print "yes" or "no" (without quotes), depending on the answer.

If your answer is "yes", then also print two space-separated integers 
denoting start and end (start must not be greater than end) indices of 
the segment to be reversed. If there are multiple ways of selecting 
these indices, print any of them.

'''

#~ import io
#~ import sys

#~ test = '''3
#~ 3 2 1'''

#~ test = '''4
#~ 2 1 3 4'''

#~ test  = '''4
#~ 3 1 2 4'''

#~ test =  '''2
#~ 1 2'''

#~ sys.stdin = io.StringIO(test)

n = int(input())
a = list(map(int, input().split()))

# identify pattern:
# increase - decrease - increase
# 1 2 3      5 4 3      5 6
# after flip
# 1 2 3      3 4 5      5 6
# for this,  
#     dec_start = 4
#     inc_start = 6
# need to flip 3,5 (=dec_start-1,inc_start-1)
# need: a[inc_start]>=a[dec_start-2]
#       a[inc_start+1]>a[dec_start-1]

def f():
   i = 1
    # skip increasing sequence
   while i<n and a[i-1]<=a[i]: i+=1 
   if i==n: return (0,0)
   dec_start = i
   largest_so_far = a[dec_start-2] if dec_start-2>=0 else float("-inf")
    # skip decreasing sequence
   while i<n and a[i-1]>=a[i] and a[i]>=largest_so_far: i+=1
   if i==n: return (dec_start-1,n-1)
   if a[i]<largest_so_far: return
    # skip increasing sequence
   inc_start = i
   largest_so_far = max(largest_so_far,a[dec_start-1])
   while i<n and a[i-1]<=a[i] and a[i]>=largest_so_far: i+=1
   if i==n: return (dec_start-1,inc_start-1)
   return
   
r = f()  
if r==None:
   print("no")
else:
   print("yes")
   print(r[0]+1,r[1]+1)

