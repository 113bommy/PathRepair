one = ['','one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
two = ['','','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
n = int(input())
if n == 0:
    print('zero')

elif n <= 19:
    print(one[n])

else:
    n = str(n)
    first = int(n[0])
    second = int(n[1])
    a = [two[first],one[second]]
    if a[1] != '':
        print('-'.join(a))
    else:
        print(a[0])