s = input("")
a,b = s.split(' ')

a = eval(a)
b = eval(b)
init = 1
tongji = 0
for init in range(1,a+1):
    shi = 1 * init
    zhong = a * init
    if b>=shi and b<=zhong and b % shi == 0:
        tongji = tongji + 1



        
print(tongji)