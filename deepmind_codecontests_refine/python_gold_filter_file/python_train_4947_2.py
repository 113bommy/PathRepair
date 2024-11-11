if __name__ == "__main__":

    a = input()
    b = input()

    len_a = len(a)
    len_b = len(b)
    maxlen = max( len_a , len_b )
    if len_a < maxlen:
        a = "0"*(maxlen-len_a) + a
    if len_b < maxlen:
        b = "0"*(maxlen-len_b) + b

    if a < b:
        print("<")
    elif a > b:
        print(">")
    else:
        print("=")