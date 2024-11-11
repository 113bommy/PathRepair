cd=input()
if cd in ('a1','a8','h1','h8'):
    print(3)
elif (cd[0] in ('a','h')) or (cd[1] in ('1','8')):
    print(5)
else:
    print(8)
