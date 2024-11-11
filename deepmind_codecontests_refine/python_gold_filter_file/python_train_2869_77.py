a = input()
b = list(range(int(a)))

#  end = ""

for i in b:
    i = input()

    try:
        int(i)
        None
    except:
        if len(i) > 100:
            None
        elif len(i) < 1:
            None
        elif len(i) > 10:  #and len(a) <= 100 and len(a) >= 1:
            end = ""
            end += i[0]
            end += str(len(i)-2)
            end += i[-1]
            print(end)
        else:
            print(i)