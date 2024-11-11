num = int(input())
l1 = ("C." * ((num+1)//2))[:num]
l2 = (".C" * ((num+1)//2))[:num]

print((num**2+1)//2)
for i in range(num):
    if i % 2 == 0:
        print(l1)
    else:
        print(l2)




