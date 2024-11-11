if __name__ == "__main__":
        n = int(input().rstrip())
        arr = list(map(int , input().rstrip().split()))

        lengthList = list()
        length = 0
        for i in range(2 , len(arr)):
                if arr[i] == arr[i - 1] + arr[i - 2]:
                        length += 1
                else:
                        lengthList.append(length + 2)
                        length = 0
                        
        if length != 0:
                lengthList.append(length + 2)

        if len(lengthList) == 0 and n <= 2:
                print(n)
        else:
                print (max(lengthList))
