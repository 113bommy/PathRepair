if __name__ == "__main__":

    n = int( input() )
    if n == 3:
        print(24)
    else:
        res = 2*4*3*(4**(n-3))
        res += (n-3)*4*3*3*(4**(n-4))
        print( res )