def main():
    n = int(input())
    a = ['zero','one','two','three','four','five','six','seven','eight','nine', 'ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
    b = ['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
    if n < 20:
        print(a[n])
    elif n % 10:
        print('%s-%s' % (b[n // 10 - 2], a[n % 10]))
    else:
        print(b[n // 10 - 2])
if __name__ == '__main__':
    main()
