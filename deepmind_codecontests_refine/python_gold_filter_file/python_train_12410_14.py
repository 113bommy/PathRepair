for i in range(int(input())):
    info = list(map(int, input().split()))
    player1= list(map(int, input().split()))
    player2= list(map(int, input().split()))
    if max(player1)> max(player2) :
        print("YES")
    else:
        print("NO")