n=int(input(),2)
a=1
for i in range(101):
    if n<=a:
        print(i)
        break
    a*=4
