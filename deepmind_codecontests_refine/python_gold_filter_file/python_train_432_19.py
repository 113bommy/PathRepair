# import sys 
import math
sword_type= int(input())

left = list(map(int,input().split()))

# print(left)
maximum= max(left)

d=0
swords_missing=0
for i in left:

    swords_missing+= maximum -i
    d=math.gcd(d,maximum-i)



# print(swords_missing)

# left= [i for i in left if i!=0]

# # print(left)
# minimum= min(left)

print("{} {}".format(int(swords_missing/d), d))


# sys.exit()