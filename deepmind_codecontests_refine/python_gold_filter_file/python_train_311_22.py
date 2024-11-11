while True:
    m, n = list(map(int, input().split()))
    if m == n == 0:
        break
    for i in range(m):
        print (("#." * 500)[i:i+n])
    print ("")

