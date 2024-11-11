a = int(input())
b = int(input())
c = int(input())

total1 = a + b*c
total2 = a*(b+c)
total3 = a*b*c
total4 = (a+b)*c
total5 = a+b+c
ans = 0

if(total1 >= total2 and total1 >= total3 and total1 >= total4 and total1 >= total5):
    ans = total1
elif(total2 >= total1 and total2 >= total3 and total2 >= total4 and total2 >= total5):
    ans = total2
elif(total3 >= total1 and total3 >= total2 and total3 >= total4 and total3 >= total5):
    ans = total3
elif(total4 >= total1 and total4 >= total2 and total4 >= total3 and total4 >= total5):
    ans = total4
elif(total5 >= total1 and total5 >= total2 and total5 >= total3 and total5 >= total4):
    ans = total5


print(ans)