n=int(input()[-1])
if n==3:
    res="bon"
elif n in [0,1,6,8]:
    res="pon"
else:
    res="hon"
print(res)