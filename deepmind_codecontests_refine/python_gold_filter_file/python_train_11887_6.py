n = int(input())
answer = ""
if (n%2)==0:
    print("NO")
else:
    for i in range(1,(2*n)+1):
        k = ((2 * i) - (i % 2)) % (2*n)
        if k == 0:
            answer += str(2*n)+" "
        else:
            answer += str(k)+" "

    print("YES")
    print(answer)