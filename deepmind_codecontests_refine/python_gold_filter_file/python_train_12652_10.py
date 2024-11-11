f1 , t1 = [int(i) for i in input().split(" ")]
f2,  t2 = [int(i) for i in input().split(" ")]
time = [str(i) for i in input().split(" ")]
time = time[0]

th, tm = time.split(":")
th =int(th)
tm = int(tm)

#print("th is {}, tm is {}".format(th,tm))

tt = ((th- 5) * 60) + tm

#print(tt)
bs = tt - t2 +1
bf = tt + t1 -1
count = 0

if bs < 0:
    bs = 0
#print("start is {}, fin is {}".format(bs,bf))

ct = (18*60) + 59
if bf > ct:
    bf = ct

#print("start is {}, fin is {}".format(bs,bf))
time = 0

for i in range(int(((18*60) + 59)/f2)+1):

    if bs <= time <= bf:
        count +=1

    time = time + f2

print(count)



