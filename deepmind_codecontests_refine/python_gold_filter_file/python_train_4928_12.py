if __name__ == '__main__':
    #print ("Started")
    n, a, b = [int(x) for x in input().split()]
    ar = list(map(int, input().split()))
    ar.sort()
    print(ar[b] - ar[b - 1])
