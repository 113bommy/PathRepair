def main():
    userInp = int(input())
    room = 0
    for i in range(userInp):
        p ,q = list(map(int,input().split()))
        if  (q-p) >= 2 :
            room +=1

    print(room)

main()