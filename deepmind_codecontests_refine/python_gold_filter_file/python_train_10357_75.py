i = int(input())
a = ['zero','one','two','three','four','five','six','seven','eight','nine','ten','eleven',
     'twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
aa = ['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']

if i in range(0,20): print(a[i])
elif i%10 == 0: print(aa[int(str(i)[0])-2])
else: print(str(aa[int(str(i)[0])-2])+"-"+str(a[int(str(i)[1])]))
