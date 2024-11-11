def countZeros(x):
    count = 0
    if '1' in x:
        b = x.index('1')
        # print("B is: ", b)
        for i in x[b:]:
            if i == '0':
                count += 1
    # print("count is: ", count)
    if (count < 6):
        return "No"
    if (count >= 6):
        return "Yes"
    else:
        return "No"

def main():
    bin = input()
    print(countZeros(bin))

if __name__ == "__main__":
    main()
