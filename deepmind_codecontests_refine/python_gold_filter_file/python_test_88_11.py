#SaveHindus
#SaveHinduTemples
#We_want_justice
#save_minority_hindu
#HumanRightsViolations
#I_Am_Feeling_unsafe_In_Bangladesh
#Save_The_Hindu_Of_Bangladesh
#save_hindu_bangladesh
#stop_hindu_oppression_bangladesh
#Stop_Communal_Attack
#Save_Bangladeshi_Hindus
#BangladeshiHinduWantSafety
#SaveBangladeshiHindus
#WeDemandSafety
#WeDemandJustice
from math import *
t = int(input())
for _ in range(t):
    n = int(input())
    li = list(map(int, input().split()))
    if n % 2 == 0:
        print("YES")
    else:
        f = 0
        for i in range(1, n):
            if li[i] <= li[i - 1]:
                f = 1
                break
        if f == 1:
            print("YES")
        else:
            print("NO")