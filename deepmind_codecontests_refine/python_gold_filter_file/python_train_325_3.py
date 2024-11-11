if __name__ == '__main__':
    n,x,y = map(int, input().split())
    ns = list(input())
    changes = 0
    for i in range(x):
        if i == y:
            if ns[n-1-i] == '0':
                changes += 1
        else:
            if ns[n-1-i] == '1':
                changes += 1
                
    print(changes)