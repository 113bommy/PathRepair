if __name__ == '__main__':
    
    n =  int(input())

    a = list(map(int,input().split()))
    if n == 2:
        if a[0] <= a[1]:
            print(0)
        else:
            print(1)
       
    else:
        pos = 1
        flag = 0
        for i in range(n-1):
            if a[i] <= a[i+1]:
                pos += 1
                flag = 1
                
            else:
                if i == 0 or flag == 1:                                            
                    if a[n-1] <= a[0]:
                        for j in range(pos,n-1):
                            if a[j] <= a[j+1]:
                                flag = 1
                            else:
                                flag = 0
                                pos = -1  
                                break           
                    else:
                        flag = 0
                        pos = -1
                        break
                else:
                    flag = 0
                    pos = - 1
                    break
                
                break
        if flag == 0:
            print(pos)
        else:
            print(n - pos)
