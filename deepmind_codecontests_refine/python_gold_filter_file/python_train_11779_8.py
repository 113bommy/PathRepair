if __name__ == '__main__':
    x , y , z = map(int, input().split())
    a , b, c = map(int, input().split())
    flag = 0
    if a >= x:
        if x == a:
            if b >= y:
                if b - y +c >= z:
                    flag = 1
        else:
            #leftover = b + c + a - x
            if b + a - x >= y:
                if b + c + a - x - y >= z:
                    flag = 1
    if flag == 1:
        print("YES")
    else:
        print("NO")
                
        