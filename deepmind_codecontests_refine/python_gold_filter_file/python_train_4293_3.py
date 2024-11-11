if __name__ == '__main__':
    for _ in range(int(input())):
        length = int(input())
        a = *map(int,input().split()),
        rest = {*range(2*length+1)} -{*a}
        answer = []
        try:
            for i in a:
                temp = min(rest-{*range(i)})
                rest-={temp}
                answer+=i,temp
            print(*answer)
        except:
            print(-1)




