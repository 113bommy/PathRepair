n = int( input() )

input_data = input()
input_data = input_data.split(' ')
arr = [ int(i) for i in input_data ]

if sum( arr ) != 0 :
    print("YES\n1\n%d %d" % (1,len(arr)) )
else:
    summa = 0
    for i in arr:
        summa += i
        if summa != 0:
            print("YES\n2")
            print("%d %d" % (1, arr.index(i)+1) )
            print("%d %d" % (arr.index(i)+2, len(arr)) )
            break
    else:
        print("NO")

