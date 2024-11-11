def MoveOn(strength, arr):
    #Sort array
    arr = sorted(arr, key=lambda x:int(x[0]))

    for i in arr:
        if strength <= int(i[0]):
            return "NO"
        else:
            strength = strength + int(i[1])

    return "YES"

if __name__ == "__main__":
    n = input().split(" ")
    arr = []
    for i in range(0,int(n[1])):
        arr.append(input().split(" "))
    print(MoveOn(int(n[0]),arr))