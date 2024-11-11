'''
#Try 1

n = (map(int,input()))
k = set(map(int,input().split()))
if 1 in k:
    print("hard")
else:
    print ("easy")
'''

input()
print("hard" if  "1" in input() else "easy")