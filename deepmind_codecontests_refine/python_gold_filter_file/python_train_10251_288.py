#Calculating_Function.py
import sys,math
num = int(sys.stdin.readline())
count_odd = count_even = 0
if(num%2==1):
    ans = int((-1)*((num+1)/2))
else:
    ans = int((num/2))
print(ans)