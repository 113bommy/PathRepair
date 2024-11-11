S = list(input())
if "L" not in S[0::2] and "R" not in S[1::2]:
    print ("Yes")
else:
    print("No")