def solve():
    width, height  = str(input()).split()
    width, height = int(width), int(height)     # convert to integers

    wide_box = width * height    
    wide_dom = 2 * 1               

    tot_dom = int(wide_box / wide_dom)

    print(tot_dom)

solve()