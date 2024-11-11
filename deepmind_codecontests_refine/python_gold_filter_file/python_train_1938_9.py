#RAVENS
#TEAM_2
#ESSI-DAYI_MOHSEN-LORENZO
import sys
from math import sqrt
input=sys.stdin.readline
R,d=map(int,input().split())
res = 0
for i in range(int(input())):
    x,y,r = map(int,input().split())
    'اول فاصله ی بین مرکزها را حساب میکنیم'
    dd = sqrt( (abs(x)**2) + (abs(y)**2) )
    'حالا وضعیت دو دایره را چک میکنیم'
    if ( dd <= abs(R-r) ) and (dd >= (R-d)+r):res+=1
print(res)


