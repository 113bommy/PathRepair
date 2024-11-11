N=int(input())
if N%10==3:
    print("bon")
elif N%10 in [0,1,6,8]:
    print("pon")
else:
    print("hon")